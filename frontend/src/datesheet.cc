/**
 *       \file       datesheet.cc
 *
 *       \brief      Function definition of datesheet class
 *
 *       \version    0.6
 *       \date       Sunday 07 April 2013 07:59:55  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include datesheet.h 
 */
#include "header/datesheet.h"

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: DateSheet()
 *      \brief  Constructor
 */

DateSheet :: DateSheet()
{
    // constructor
    totalCols = 3;
    tableHeading.resize(totalCols);
    i = 0;
    tableHeading[i++] = "Date";
    tableHeading[i++] = "Exams Code";
    tableHeading[i++] = "Delete Row";
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: ReadRollNoDetail()
 *      \brief  Reading roll no details filled by user
 */

void DateSheet :: ReadRollNoDetail()
{
//    page.ContentType();

    projectID = readField.ReadFieldValue(fieldName.projectID);
    projectType = readField.ReadFieldValue(fieldName.projectType);
    totalClasses = StringToInt(readField.ReadFieldValue(
                               fieldName.totalClasses));

    className.resize(totalClasses);
    subjectCode.resize(totalClasses);
    prefix.resize(totalClasses);
    startRollNo.resize(totalClasses);
    endRollNo.resize(totalClasses);
    notIncluded.resize(totalClasses);

    for(i = 0; i < totalClasses; i++)
    {
        j = i + 1;
        className[i] = readField.ReadFieldValue(fieldName.className,
                                                j);

        subjectCode[i] = readField.ReadFieldValue(
                         fieldName.subjectCode, j);
        
        prefix[i] = readField.ReadFieldValue(fieldName.prefix, j);

        startRollNo[i] = readField.ReadFieldValue(
                         fieldName.startRollNo, j);

        endRollNo[i] = readField.ReadFieldValue(
                       fieldName.endRollNo, j);

        notIncluded[i] = readField.ReadFieldValue(
                         fieldName.notIncluded, j);

    }
 
    if(projectType == "Old")
    {
        where = "ProjectID = " + projectID;      
        database.SelectColumn(date, "Date", "DateSheet", where);

        if(date.size() <= 0)
        {
            SetDefaultValue();
        }
        else
        {
            database.SelectColumn(examCode, "ExamCode",
                                  "DateSheet", where);
            totalDays = date.size();
        } 
    }
    else
    {
        SetDefaultValue();
    }

    WriteRollNoDetail();
//    DateSheetPage();
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: WriteRollNoDetail()
 *      \brief  Writing rol no details into database
 */

void DateSheet :: WriteRollNoDetail()
{
    where = "ProjectID = " + projectID;
    database.SelectColumn(vecTemp, "Prefix", "RollNoDetail",
                          where);

    if(vecTemp.size() > 0 )
    {
        where = "ProjectID = " + projectID;
        database.DeleteQuery("RollNoDetail", where);
    }

    for(i = 0; i < totalClasses; i++)
    {
        where = "ProjectID = " + projectID + " AND SubjectCode =\"" +
                subjectCode[i] + "\" AND ClassName =\"" + className[i] 
                + "\"";

        database.SelectColumn(classID, "ClassID", "ClassDetail",
                              where);
        database.InsertRollNoDetail(projectID, classID[i], prefix[i],
                                    startRollNo[i], endRollNo[i],
                                    notIncluded[i]);
    }

    /* write roll no detail into file */

    temp = FileName(ROLLNO_DETAIL, projectID, 1);
    outFile.open(temp.c_str());

    outFile << totalClasses << endl;
    for(i = 0; i < totalClasses; i++)
    {
        trim(prefix[i]);
        trim(startRollNo[i]);
        trim(endRollNo[i]);

        erase_all(notIncluded[i], " ");

        outFile << prefix[i] << "-" << endl
                << startRollNo[i] << "-" << endRollNo[i] << endl
                << notIncluded[i] << endl;
    }

    outFile.close();
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: SetDefaultValue()
 *      \brief  Setting default values for i/p field of datesheet
 */

void DateSheet :: SetDefaultValue()
{
    totalDays = 1;
    date.resize(totalDays);
    examCode.resize(totalDays);

    date[0] = "12/04/2013";
    examCode[0] = "IT-102, CSE 120";
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: DateSheetPage()
 *      \brief  DateSheet Page for taking I/P from user
 */

void DateSheet :: DateSheetPage()
{
    page.ContentType();

    ReadRollNoDetail();

    Header("DateSheet");

    page.DivStart("DivDateSheet", "");

    page.LogoutLink();

    cout << page.brk;

    page.FormStart("FormDateSheet", "room", "POST");

    cout << page.startH1 << "Date Sheet" 
         << page.endH1 << page.brk;
    
    ErrorMessage(msg);

    page.InputField("hidden", fieldName.projectID, projectID);
    page.InputField("hidden", fieldName.totalDays, 
                    IntToString(totalDays));
    page.InputField("hidden", fieldName.projectType, projectType);
    
    page.InputField("button", "AddRow", 
                    "addRows('TableDateSheet', 'TotalDays', 'date')",
                    "Add Row");
/*     
    page.InputField("button", "DeleteRow", 
                    "deleteRow('TableDateSheet', 'TotalDays')",
                    "Delete Row");
*/
    cout << page.brk << page.brk;

    page.TableStart("TableDateSheet", "");
   
    cout << page.startTR;
    for(i = 0; i < totalCols; i++)
    {   
        cout << page.startTH << tableHeading[i] << page.endTH;
    }
    cout << page.endTR;

    if(projectType == "Old")// && (className.size() >= 1 ) || 
//       subjectName.size() >= 1 || subjectCode.size() >= 1 ))
    {
        for(i = 0; i < totalDays; i++)
        {
            cout << page.startTR;
        
            cout << page.startTD;
            page.InputField("text", fieldName.date, (i + 1),
                            date[i], date[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.examCode, (i + 1),
                            examCode[i], examCode[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("button", "DeleteRow", 
                            "delRow('TotalDays')",
                            "Delete Row");
            cout << page.endTD;


            cout << page.endTR;
        }
    }
    else
    {
        for(i = 0; i < totalDays; i++)
        {
            cout << page.startTR;
        
            cout << page.startTD;
            page.InputField("text", fieldName.date, (i + 1),
                            date[i]);
            cout << page.endTD;
        
            cout << page.startTD;
            page.InputField("text", fieldName.examCode, (i + 1),
                            examCode[i]);
            cout << page.endTD;

            cout << page.startTD;
            page.InputField("button", "DeleteRow", 
                            "delRow('TotalDays')",
                            "Delete Row");
            cout << page.endTD;


            cout << page.endTR;
        }
    }
   
    page.TableEnd();
  
    cout << page.brk << page.brk
         << " Same room and exam details for each day ";
    page.InputField("radio", fieldName.sameDetail, "Yes");
    page.Label(fieldName.sameDetail, "Yes");

    page.InputField("radio", fieldName.sameDetail, "No");
    page.Label(fieldName.sameDetail, "No");
   
    cout << page.brk << page.brk;

    page.Button("next", "submit", "btn", "NEXT");

    page.FormEnd();
    page.DivEnd();

    Footer();
}

/**
 *      \class  DateSheet
 *      \fn     DateSheet :: ~DateSheet()
 *      \brief  DEstructor
 */

DateSheet :: ~DateSheet()
{
    // destructor
}

/*
 * ===================================================================
 *
 *       Filename:  inputfieldname.cc
 *
 *    Description:  Definition of InputFieldName's member functions.
 *
 *        Version:  0.7
 *        Created:  Saturday 16 February 2013 02:29:48  IST
 *       Compiler:  g++
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include header file that contains InputFieldName Class's
 *  Declaration
 *------------------------------------------------------------------*/

#include "header/inputfieldname.h"

/**-------------------------------------------------------------------
 *  Definition of member functions
 *------------------------------------------------------------------*/

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldName
 *      Method:  InputFieldName :: InputFieldName()
 * Description:  Constructor calls SetFieldNames()
 *--------------------------------------------------------------------
 */

InputFieldName :: InputFieldName()
{
    SetFieldNames();
}

/**
 *--------------------------------------------------------------------
 *       Class:  InputFieldName
 *      Method:  InputFieldName :: SetFieldNames()
 * Description:  Assign Values of field names in its respective
 * variables.
 *--------------------------------------------------------------------
 */

void InputFieldName :: SetFieldNames()
{
    /* Assign values of class details */

    className       =   "ClassName";
    totalClasses    =   "TotalClasses";
    totalSubjects   =   "TotalSubjects";
    subjectCode     =   "SubjectCode";
    subjectName     =   "SubjectName";
    classID         =   "ClassID";
    
    /* variable for roll no fields */

    prefix          =   "Prefix";
    startRollNo     =   "StartRollNo";
    endRollNo       =   "EndRollNo";
    notIncluded     =   "NotIncluded";

    /* Login page fields */

    emailID         =   "EmailID";
    password        =   "Password";
    retypePassword  =   "RetypePassword";
    key             =   "Key";

    /* Project Detail */

    projectName     =   "ProjectName";
    projectID       =   "ProjectID";
    projectType     =   "ProjectType";

    /* Room Detail Variables */

    totalCentres    =   "TotalCentres";
    totalRooms      =   "TotalRooms";
    centreName      =   "CentreName";
    roomNo          =   "RoomNo";
    rows            =   "Rows";
    columns         =   "Columns";

    /* Strategy field */

    strategyChoice  =   "StrategyChoice";

    /* Examination field's value */

    examName        =   "ExamName";
    examDate        =   "ExamDate";
    examSession     =   "ExamSession";
    examTime        =   "ExamTime";
    examVenue       =   "ExamVenue";

    /* Date Sheet field values */

    date            =   "Date";
    examCode        =   "ExamCode";
    totalDays       =   "TotalDays";
    
    /* Variable for holding value of same detail */
    sameDetail      =   "SameDetail";

    /* Variables for row index and last row in table */
    lastRow         =   "LastRow";
    rowIndex        =   "RowIndex";
}

/*
 * ===================================================================
 *
 *       Filename:  database.h
 *
 *    Description:  Declaring Database class for using database.
 *
 *        Version:  0.6
 *        Created:  Friday 22 February 2013 12:48:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include header.h and database.h
 *------------------------------------------------------------------*/

#include "header.h"
#include "database-detail.h"
#include <mysql.h>

/**
 * ===================================================================
 *        Class:  Database
 *  Description:  Database class for database accessability
 * ===================================================================
 */

class Database
{
    protected:
        /** MySQL connectivity Variables */
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;

        /** unsigned int variable  */
        unsigned int numrows;
        
        /** Table names tTablename */
        string tLogin, tRegister, tProjectDetail;

        int i, j;
        string query;

    public:
        /** Database Constructor */
        Database();
        
        /** For executing MySQL query */
        void SelectQuery(string column, string table, 
                         vector<string> & result);

        /** For inserting new user in database */
        void InsertIntoUser(string userEmailID, string userPassword);

        /** Insert query with one argument */
        void InsertQuery(string query);

        /** Insert Query for adding value in one column */
        void InsertQuery(string column, string value, string table);

        /** Insert into table with where clause */
        void InsertQuery(string column, string value, string table,
                         string whereClause);

        /** Database Destructor */
        ~Database();
};

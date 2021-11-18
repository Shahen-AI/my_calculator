#include "../my_calc.h"

void creating_table(MYSQL	*con, char *arg)
{
	char *sql;

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit (1);
	}
	// set here mysql login and password 
	if (mysql_real_connect(con, "localhost", "mysql_login", "mysql_password",
	"calcDB", 0, NULL, 0) == NULL)
	{
		if (strncmp("Unknown database", mysql_error(con), 16) == 0)
		{
			mysql_real_connect(con, "localhost", "mysql_login", "mysql_password",
				NULL, 0, NULL, 0);
			if (mysql_query(con, "CREATE DATABASE calcDB"))
				finish_with_error(con);
			mysql_close(con);
			con = mysql_init(NULL);
			mysql_real_connect(con, "localhost", "mysql_login", "mysql_password",
				"calcDB", 0, NULL, 0);
		}
		else
			finish_with_error(con);
	}
	if (mysql_query(con,
	"CREATE TABLE IF NOT EXISTS Calculations(id INT PRIMARY KEY AUTO_INCREMENT, Expression VARCHAR(255), Answer DOUBLE)"))
		finish_with_error(con);
	sql = ft_strjoin("INSERT INTO Calculations(Expression) VALUES('", arg);
	sql = ft_strjoin(sql, "')");
	if (mysql_query(con, sql))
		finish_with_error(con);
}

void inserting_table(MYSQL	*con, char *arg, int val)
{
	char *sql;
	int temp_id;

	temp_id = mysql_insert_id(con);
	sql = ft_strjoin("DELETE from Calculations where id=", ft_itoa(temp_id));
	if (mysql_query(con, sql))
		finish_with_error(con);
	sql = ft_strjoin("INSERT INTO Calculations(Expression,Answer) VALUES('", arg);
	sql = ft_strjoin(sql, "','");
	sql = ft_strjoin(sql, ft_itoa(val));
	sql = ft_strjoin(sql, "')");
	if (mysql_query(con, sql))
		finish_with_error(con);
	if (mysql_query(con, "SET @reset = 0"))
		finish_with_error(con);
	if(mysql_query(con, "UPDATE Calculations SET id = @reset:= @reset + 1"))
		finish_with_error(con);
}

char *get_from_db(MYSQL	*con)
{
	char    	*res;
	MYSQL_ROW	row;
	MYSQL_RES 	*result;

	if (mysql_query(con, "SELECT Expression FROM Calculations"))
		finish_with_error(con);

	result = mysql_store_result(con);
	if (result == NULL)
		finish_with_error(con);

	while ((row = mysql_fetch_row(result)))
		res = row[0];

	mysql_free_result(result);
	return (res);
}

int insert_from_db(MYSQL	*con)
{
	int			num;
	char    	*res;
	MYSQL_ROW	row;
	MYSQL_RES 	*result;

	if (mysql_query(con, "SELECT Answer FROM Calculations"))
		finish_with_error(con);

	result = mysql_store_result(con);
	if (result == NULL)
		finish_with_error(con);

	while ((row = mysql_fetch_row(result)))
		res = row[0];
	num = ft_atoi(res);
	mysql_free_result(result);
	return (num);
}

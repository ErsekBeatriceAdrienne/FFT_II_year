--drop the table if it exists
DROP TABLE users;
--creating the users table
CREATE TABLE users (
	id INT PRIMARY KEY IDENTITY(1,1),
	first_name NVARCHAR(100)			NOT NULL,
	last_name NVARCHAR(100)				NOT NULL,
	email NVARCHAR(100)					NOT NULL,
	password_user NVARCHAR(200)			NOT NULL,
	country NVARCHAR(100)				NOT NULL,
	phone_number NVARCHAR(100)			NOT NULL,
	language_user NVARCHAR(100)			NOT NULL,
	profile_picture VARBINARY(MAX)				,
	profile_picture_type NVARCHAR(5)			,
	gender NVARCHAR(10)					NOT NULL,
	location_user NVARCHAR(100)			NOT NULL,
	postal_code NVARCHAR(100)
);

--describe 
SP_COLUMNS users;

--insert some fake data
INSERT INTO users 
		(first_name,last_name,email,password_user,country,phone_number,language_user,gender,location_user)
VALUES ('Gáll',
		'Gyurika',
		'gyurikagyuri2002@gmail.com',
		'gyurika123456789',
		'Romania',
		'0723323432',
		'hungarian',
		'male',
		'Str. Budiului 1000.');

SELECT first_name, last_name, gender
FROM users
WHERE id = 1;
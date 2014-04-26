Scott Nevin
CSC-7 43732

	Simple log-in encryption program

	This program saves information for up to three separate users
in separate files. It takes a name and a password and uses the ELF hash 
to encrypt them. Also it saves a secret message for the user in their file
encrypted by basic ASCII manipulation. 

Sample input:

Are you a new user? y/n
n

Enter Name: Scott
Password: Robot

	You can choose to create new login data, or log in to an existing account.
The program will then take you to a menu, to read your secret message, change your 
secret message, or log out.

	To reinitialize a file to blank, simply delete the data inside and save the 
text document with only a '0', this is how the program recognizes an empty file.

	Known issues
	the program has no answer if two files contain the same name. Since the password
validation is based on finding which password belongs to which name, having two files under
the same name would cause the program to fail.




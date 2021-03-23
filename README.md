Lab0PA
First Initialize repository

git init

HOW TO COMMIT FOR GITHUB

FIRST SET THE URL FOR PUSH

1. git remote add origin https://github.com/Chapita98/LabPa2021
2. And verifie it with git remote

NOW COMMIT : 

1. git status // For checking what files are going to commit
2. git add . // the . stands for all, you can specify which files you want to commit
3. git commit -m "Reference message" // Commit the repository and a message for telling others what you have changed
4. git push origin master // Pushes the files to the repo

FOR PULLING (First set the URL, go to Step 1)

1. git pull origin master

IF PULL NOT WORKS TRY THIS: 

1. git fetch --all 
2. git reset --hard origin/master

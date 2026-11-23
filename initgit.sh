
$ echo '# '${1} >> README.md
git init
git add README.md
git add -A
git commit -m "first commit"
git branch -m main
git remote add origin https://github.com/cthorburn/${1}.git
git push -u origin main


# SASH
An attempt to make a shell.<br>
Tracking history of commands, using arrow keys to get history and autocomplete using tab are done by using readline library provided by GNU.<br>
Currently the commands using pipes are not implemented in this shell.
# To install readline library
Write this command in terminal:<br>
sudo apt-get install libreadline-dev
# To run the shell
Paste this line in your .bashrc<br>
alias gmm="gcc myshell.c -L/usr/local/lib -I/usr/local/include -lreadline "<br>
Then open terminal and write:<br>
gmm<br>
./a.out<br>
And there's your shell :)

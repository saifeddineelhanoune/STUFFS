/* install tree cmd with brew in macos if it won't be installed program in c */

#include <unistd.h>
#include <stdlib.h>

void       install_tree_cmd()
{
    // executable path of tree;
    char *tree = "/usr/local/bin/tree";
    // executable path of brew;
    char *brew = "/usr/local/bin/brew";
    //you can use the first path of sh directly and start using the default shell on your os
    char *i_brew = "/bin/bash -c \"/bin/bash -c \\\"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\\\"\"; echo $?\"";
    char *i_tree = "/bin/bash -c \"brew install tree || true; echo $?\"";
    if (access(tree, X_OK)) {
        int brew_installed = system(brew);
        if (brew_installed == -1)
            system(i_brew);
        system(i_tree);
    }
    //execution
    char **arguments = {tree, NULL};
    char **env = {NULL};
    execve(tree, arguments, env);
    //this message should be displayed in case of faillure of execve
    write(2, "error execution and installing tree command", 43);
}
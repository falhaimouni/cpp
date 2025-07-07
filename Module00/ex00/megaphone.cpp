#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    int i = 1;
    while (argv[i])
    {
	    int j = 0;
	    while (argv[i][j]){ 
		    std::cout << (char)std::toupper(argv[i][j]);
	    j++;
	    }
	    if (i < argc - 1)
		    std::cout << " ";
	    i++;
    }
    std::cout << std::endl;
	return(0);
}


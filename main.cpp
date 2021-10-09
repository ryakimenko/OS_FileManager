#include "FileManager.h"
int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        std::cout << "Invalid amount of arguments.\nAvailable options: --create --read --copy --move --remove --read_dir --create_Slink --create_Hlink\n";
        return -1;
    }

    std::string option = argv[1];

    if (option.compare("--create") == 0)
    {
        if (argc != 3)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::create(argv[2]);
    }
    else if (option.compare("--read") == 0)
    {
        if (argc != 3)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::read(argv[2]);
    }
    else if (option.compare("--copy") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::copy(argv[2], argv[3]);
    }
    else if (option.compare("--move") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::move(argv[2], argv[3]);
    }
    else if (option.compare("--remove") == 0)
    {
        if (argc != 3)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::Remove(argv[2]);
    }
    else if (option.compare("--read_dir") == 0)
    {
        if (argc != 3)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::read_dir(argv[2]);
    }
    else if (option.compare("--create_Slink") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::create_Slink(argv[2], argv[3]);
    }
    else if (option.compare("--create_Hlink") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Invalid amount of arguments.\n";
            return -1;
        }
        FM::create_Hlink(argv[2], argv[3]);
    }
    else
    {
        std::cout << "Invalid option.\nAvailable options: --create --read --copy --move --remove --read_dir --create_link\n";
        return -1;
    }
    return 0;
}
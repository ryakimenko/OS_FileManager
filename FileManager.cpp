#include "FileManager.h"

namespace FM
{
    int create(std::string file_name)
    {
        FILE *f;
        if ((f = fopen(file_name.c_str(), "w")) == NULL)
        {
            std::cout << "File creating failed\n";
            return -1;
        }
        fclose(f);
        return 1;
    }

    void read(std::string file_name)
    {
        int ch;
        FILE *f = fopen(file_name.c_str(), "r");
        if (!f)
        {
            std::cout << "File reading failed\n";
            return;
        }
        while (!feof(f) && !ferror(f))
        {
            ch = getc(f);
            if (ch != EOF)
            {
                putchar(ch);
            }
        }
        putchar('\n');
        fclose(f);
    }

    void copy(std::string file_name, std::string file_copy)
    {
        if (!file_name.compare(file_copy))
        {
            std::cout << "File names are equal, can't copy\n";
            return;
        }
        FILE *in;
        FILE *out;
        if ((in = fopen(file_name.c_str(), "r")) == NULL || (out = fopen(file_copy.c_str(), "w")) == NULL)
        {
            std::cout << "File coping failed";
            return;
        }
        char ch;
        while (!feof(in) && !ferror(in))
        {
            ch = getc(in);
            if (ch != EOF)
            {
                fprintf(out, "%c", ch);
            }
        }
        fclose(in);
        fclose(out);
    }

    void move(std::string file_name, std::string move_path)
    {
        if (!file_name.compare(move_path))
        {
            std::cout << "File names are equal, can't move\n";
            return;
        }
        FILE *in;
        FILE *out;
        if ((in = fopen(file_name.c_str(), "r")) == NULL || (out = fopen(move_path.c_str(), "w")) == NULL)
        {
            std::cout << "File moving failed\n";
            return;
        }
        char ch;
        while (!feof(in) && !ferror(in))
        {
            ch = getc(in);
            if (ch != EOF)
            {
                fprintf(out, "%c", ch);
            }
        }
        fclose(in);
        remove(file_name.c_str());
        fclose(out);
    }

    void Remove(std::string file_name)
    {
        if ((remove(file_name.c_str())) == -1)
        {
            std::cout << "File removing failed\n";
            return;
        }
    }

    void read_dir(std::string dir_name)
    {
        auto d = opendir(dir_name.c_str());
        struct dirent *dir;
        if (d == NULL)
        {
            std::cout << "Can't read this directory\n";
            return;
        }
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }
    }

    void create_Slink(std::string file_name, std::string link_name)
    {
        if (symlink(file_name.c_str(), link_name.c_str()) != 0)
        {
            std::cout << "Failed to create soft link\n";
            return;
        }
    }

    void create_Hlink(std::string file_name, std::string link_name)
    {
        if (link(file_name.c_str(), link_name.c_str()) != 0)
        {
            std::cout << "Failed to create hard link\n";
            return;
        }
    }
}
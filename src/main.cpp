#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    


    fs::path current_path = fs::current_path();
    std::string input;
    while (true) {
        std::cout << current_path.string() << "\ $DOX: ";
        std::getline(std::cin, input);

        if (input == "dox --version") {
            std::cout << "*******************************" << std::endl;
            std::cout << "* (C) Kaissou Teams 2021-2022 *" << std::endl;
            std::cout << "*       Dox Beta 1.0.0        *" << std::endl;
            std::cout << "*            GPL V3           *" << std::endl;
            std::cout << "*******************************" << std::endl;
        }
        if (input == "help"){
            printf("------- Dox 1.0 Beta Commands -------\n");
            printf("-- help : see all commands\n");
            printf("-- exit : exit the terminal\n");
            printf("-- cd : go to the directory\n");
            printf("-- mkdir : make folders\n");
            printf("-- rm : remove folders/files\n");
            printf("-- ls : see the directory\n");
            printf("-- dox : see dox terminal information\n");
            printf("------------------------------------\n");


        }
        // exit
        if (input == "exit") {
        std::string exited;
        std::cout << "Exit the Terminal? (Y/N): ";
        std::getline(std::cin, exited);

        if (exited == "Yes" || exited == "Y" || exited == "n") {
            return 0;
        } else if (exited == "No" || exited == "N" || exited == "n") {
        continue;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        }

        // cd ..
        if (input == "cd .."){
            current_path = current_path.parent_path();
            fs::current_path(current_path);
        }

        // mkdir
        if (input.substr(0, 6) == "mkdir ") {
            std::string new_directory = input.substr(6);
            fs::create_directory(new_directory);
            std::cout << "Répertoire créé : " << new_directory << std::endl;
        }

    // 
        if (input.substr(0, 3) == "rm ") {
            std::string file_to_remove = input.substr(3);
            fs::path file_path = current_path / file_to_remove;
            if (fs::exists(file_path)) {
                fs::remove(file_path);
                std::cout << "File Deleted : " << file_path << std::endl;
            } else {
                std::cout << "Error 404 | file not found" << std::endl;
            }
        }
        if (input == "ls") {
            for (const auto& entry : fs::directory_iterator(current_path)) {
                std::cout << entry.path().filename().string() << std::endl;
        }
    }
        if (input.substr(0, 3) == "cd ") {
            std::string directory_to_go = input.substr(3);
            fs::path directory_path = current_path;
            directory_path.append(directory_to_go);
            if (fs::is_directory(directory_path)) {
                current_path = directory_path;
                fs::current_path(current_path);
            } else {
                std::cout << "Directory not found" << std::endl;
            }
        }
  }
    return 0;
}

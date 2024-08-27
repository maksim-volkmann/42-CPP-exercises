/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:41:08 by mvolkman          #+#    #+#             */
/*   Updated: 2024/08/27 18:41:44 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
private:
    void debug(void) {
        std::cout << "DEBUG: I love having extra bacon!" << std::endl;
    }
    void info(void) {
        std::cout << "INFO: I cannot believe adding extra bacon costs more!" << std::endl;
    }
    void warning(void) {
        std::cout << "WARNING: I think I deserve some free bacon!" << std::endl;
    }
    void error(void) {
        std::cout << "ERROR: This is unacceptable! I want to speak to the manager!" << std::endl;
    }

public:
    void complain(std::string level) {
        // Define a dispatch table as an array of pairs (string, function pointer)
        typedef void (Harl::*HarlMemFn)(void);
        struct DispatchEntry {
            std::string level;
            HarlMemFn function;
        };

        // Array of DispatchEntries mapping strings to member function pointers
        DispatchEntry dispatchTable[] = {
            { "DEBUG", &Harl::debug },
            { "INFO", &Harl::info },
            { "WARNING", &Harl::warning },
            { "ERROR", &Harl::error }
        };

        // Loop through the dispatch table and call the matching function
        for (int i = 0; i < 4; i++) {
            if (dispatchTable[i].level == level) {
                // Call the appropriate member function
                (this->*(dispatchTable[i].function))();
                return;
            }
        }

        std::cout << "Unknown level: " << level << std::endl;
    }
};


int main() {
    Harl harl;
    harl.complain("DEBUG");    // Calls harl.debug()
    harl.complain("INFO");     // Calls harl.info()
    harl.complain("WARNING");  // Calls harl.warning()
    harl.complain("ERROR");    // Calls harl.error()
    return 0;
}

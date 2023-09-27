#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

bool isInRange(std::string input);
bool isNumeric(std::string s);
std::string prompt(std::string_view msg = "> ",
				   bool (*validator_fn)(std::string) = NULL,
				   std::string err_msg = "",
				   bool reprompt_on_fail = false);
std::string stringSlice(std::string s, int start, int stop);

#endif

/*
 * IO.h
 *
 *  Created on: Oct 10, 2017
 *      Author: AntonioMontana
 */

#ifndef UTILS_IO_H_
#define UTILS_IO_H_

#include <string>
#include <iostream>
#include <climits>

namespace Utils {

class IO {
public:
	IO();
	virtual ~IO();

	int readInt(std::string title);
	std::string readString(std::string title);

	void write(std::string text);
	void writeln(std::string text);
};

} /* namespace Utils */

#endif /* UTILS_IO_H_ */

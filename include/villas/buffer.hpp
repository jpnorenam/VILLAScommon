/** A simple growing buffer.
 *
 * @file
 * @author Steffen Vogel <stvogel@eonerc.rwth-aachen.de>
 * @copyright 2014-2020, Institute for Automation of Complex Power Systems, EONERC
 * @license GNU General Public License (version 3)
 *
 * VILLAScommon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *********************************************************************************/

#pragma once

#include <cstdlib>

#include <jansson.h>

#include <villas/common.hpp>

namespace villas {

class Buffer {

public:
	char *buf;
	size_t len;
	size_t size;

	Buffer(size_t size);

	~Buffer();

	void clear();

	int append(const char *data, size_t len);

	int parseJson(json_t **j);

	int appendJson(json_t *j);
};

} /* namespace villas */

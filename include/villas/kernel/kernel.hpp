/** Linux kernel related functions.
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

#include <cstddef>

#include <villas/version.hpp>

namespace villas {
namespace kernel {

/** Get the version of the kernel. */
utils::Version getVersion();

#if WITH_CAP
#include <sys/capability.h>

/** Check if current process has capability \p cap.
 *
 * @retval 0 If capabilty is present.
 * @retval <0 If capability is not present.
 */
int check_cap(cap_value_t cap);
#endif

/** Get number of reserved hugepages. */
int get_nr_hugepages();

/** Set number of reserved hugepages. */
int set_nr_hugepages(int nr);

/** Get kernel cmdline parameter
 *
 * See https://www.kernel.org/doc/Documentation/kernel-parameters.txt
 *
 * @param param The cmdline parameter to look for.
 * @param buf The string buffer to which the parameter value will be copied to.
 * @param len The length of the buffer \p value
 * @retval 0 Parameter \p key was found and value was copied to \p value
 * @reval <>0 Kernel was not booted with parameter \p key
 */
int get_cmdline_param(const char *param, char *buf, size_t len);

/** Checks if a kernel module is loaded
 *
 * @param module the name of the module
 * @retval 0 Module is loaded.
 * @reval <>0 Module is not loaded.
 */
int module_loaded(const char *module);

/** Load kernel module via modprobe */
int module_load(const char *module);

/** Set parameter of loaded kernel module */
int module_set_param(const char *module, const char *param, const char *value);

/** Get cacheline size in bytes */
int get_cacheline_size();

/** Get the size of a standard page in bytes. */
int get_page_size();

/** Get the size of a huge page in bytes. */
int get_hugepage_size();

/** Get CPU base frequency */
int get_cpu_frequency(uint64_t *freq);

/** Set SMP affinity of IRQ */
int irq_setaffinity(unsigned irq, uintmax_t aff , uintmax_t *old);

} /* namespace villas */
} /* namespace kernel */

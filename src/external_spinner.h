/*
 * Copyright © 2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alexandros Frantzis <alexandros.frantzis@canonical.com>
 */

#ifndef USC_EXTERNAL_SPINNER_H_
#define USC_EXTERNAL_SPINNER_H_

#include "spinner.h"

#include <string>
#include <sys/types.h>
#include <mutex>

namespace usc
{

class ExternalSpinner : public Spinner
{
public:
    ExternalSpinner(std::string const& executable,
                    std::string const& mir_socket);
    ~ExternalSpinner();

    void ensure_running() override;
    void kill() override;
    pid_t pid() override;

private:
    std::string const executable;
    std::string const mir_socket;
    std::mutex mutex;
    pid_t spinner_pid;
};

}

#endif

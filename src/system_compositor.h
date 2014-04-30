/*
 * Copyright © 2013 Canonical Ltd.
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
 * Authored by: Robert Ancell <robert.ancell@canonical.com>
 */

#ifndef SYSTEM_COMPOSITOR_H_
#define SYSTEM_COMPOSITOR_H_

#include "dm_connection.h"

namespace mir { namespace scene { class Session; } }

class SystemCompositorShell;
class SystemCompositorServerConfiguration;

class SystemCompositor : public DMMessageHandler
{
public:
    void run(int argc, char **argv);
    void pause();
    void resume();

private:
    std::shared_ptr<SystemCompositorServerConfiguration> config;
    std::shared_ptr<SystemCompositorShell> shell;
    boost::asio::io_service io_service;
    std::shared_ptr<DMConnection> dm_connection;

    void set_active_session(std::string client_name);
    void set_next_session(std::string client_name);
    void main();
    void qt_main(int argc, char **argv);
};

#endif /* SYSTEM_COMPOSITOR_H_ */

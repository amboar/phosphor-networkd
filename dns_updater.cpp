#include "config.h"
#include "dns_updater.hpp"

#include <phosphor-logging/log.hpp>
#include <xyz/openbmc_project/Common/error.hpp>
#include <phosphor-logging/elog-errors.hpp>
#include <sdbusplus/bus.hpp>

#include <fstream>

namespace phosphor
{
namespace network
{
namespace dns
{
namespace updater
{

void updateDNSEntries(std::istream& in, std::ostream& out)
{

    out << "### Generated by phosphor-networkd ###\n";

    for (std::string line; std::getline(in, line);)
    {
        auto index = line.find("DNS=");
        if(index != std::string::npos)
        {
            auto dns = line.substr(index + 4);
            out << "nameserver " << dns << "\n" ;
        }
    }

    out.flush();

    return;
}

} // namespace updater
} // namespace dns
} // namespace network
} // namespace phosphor

/******************************************************************************************
 * Copyright (C) 2020 by Lucas Vieira                                                     *
 *                                                                                        *
 * This file is part of chemistry-nao2gto.                                                *
 *                                                                                        *
 *   dead-reckoning simulation is free software: you can redistribute it and/or modify it *
 *   under the terms of the GNU Lesser General Public License as published                *
 *   by the Free Software Foundation, either version 3 of the License, or                 *
 *   (at your option) any later version.                                                  *
 *                                                                                        *
 *   dead-reckoning simulation is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of                       *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                        *
 *   GNU Lesser General Public License for more details.                                  *
 *                                                                                        *
 *   You should have received a copy of the GNU Lesser General Public License             *
 *   along with dead-reckoning simulation. If not, see <http://www.gnu.org/licenses/>.    *
 *****************************************************************************************/

#include <pugixml.hpp>
#include "InputHandler.h"
#include "exceptions/LoadException.h"

using namespace std;

namespace nao2gto {

    /**
     * InputHandler constructor
     *
     * @param filename
     * @throw nao2gto::exceptions::LoadException
     */
    InputHandler::InputHandler(const char *filename) {
        this->document = pugi::xml_document();

        auto result = this->document.load_file(filename);
        if (!result) {
            throw nao2gto::exceptions::LoadException();
        }

        std::cout << result << std::endl;
    }

    /**
     * Get the mass attribute
     *
     * @return double
     */
    double InputHandler::getMass() {
        auto value = this->document.child("ion").child("mass").child_value();
        return stod(value);
    }
}
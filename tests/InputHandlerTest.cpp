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

#include <InputHandler.h>
#include <catch2/catch.hpp>

using namespace nao2gto;

TEST_CASE("InputHandler constructor") {
    InputHandler handler = InputHandler("../tests/test_input/input.ion.xml");
    REQUIRE(handler.getMass() == 1.01);
}
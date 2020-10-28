/*
 * This file is part of NectarJS
 * Copyright (c) 2017 - 2020 Adrien THIERRY
 * http://nectarjs.com - https://seraum.com/
 *
 * sources : https://github.com/nectarjs/nectarjs
 * 
 * NectarJS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NectarJS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NectarJS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

function __NJS_NATIVE_OBJECT_KEYS(_obj)
{
	return __NJS_Object_Keys(_obj);
};

function __NJS_NATIVE_OBJECT_FREEZE(_obj)
{
	if(_obj)
	{
		if(_obj.type == NJS::Enum::Type::Object)
		{
			((NJS::Class::Object*)_obj.data.ptr)->property.set(0, 1);
			return _obj;
		}
	}
};

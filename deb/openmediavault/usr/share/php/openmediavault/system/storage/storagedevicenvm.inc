<?php
/**
 * This file is part of OpenMediaVault.
 *
 * @license   https://www.gnu.org/licenses/gpl.html GPL Version 3
 * @author    Volker Theile <volker.theile@openmediavault.org>
 * @copyright Copyright (c) 2009-2025 Volker Theile
 *
 * OpenMediaVault is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * OpenMediaVault is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenMediaVault. If not, see <https://www.gnu.org/licenses/>.
 */
namespace OMV\System\Storage;

/**
 * This class provides a simple interface to handle Non Volatile Memory
 * (NVM) devices.
 * @ingroup api
 */
class StorageDeviceNVM extends StorageDevice implements SmartInterface {
	use SmartTrait;

	public function isRotational() {
		return FALSE;
	}

	public function getSmartDeviceType() {
		return "nvme";
	}

	public function getVendor() {
		$filename = sprintf("/sys/block/%s/device/device/vendor",
			$this->getDeviceName(TRUE));
		if (file_exists($filename)) {
			return trim(file_get_contents($filename));
		}
		return parent::getVendor();
	}
}

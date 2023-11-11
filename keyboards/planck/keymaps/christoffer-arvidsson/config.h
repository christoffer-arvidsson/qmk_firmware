/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Enable front leds
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_USER_LEDS

#undef TAPPING_TERM
#define TAPPING_TERM 160
#define QUICK_TAP_TERM 0

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Cross case
// NOTE: remove when capslock works on work laptop
#define CAPSWORD_USE_SHIFT

#ifdef AUDIO_ENABLE
#define AUDIO_INIT_DELAY
#define STARTUP_SONG SONG(COLEMAK_SOUND)
#define GOODBYE_SONG SONG(MINOR_SOUND)
#endif

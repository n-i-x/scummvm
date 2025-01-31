/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef GUI_LAUNCHER_DIALOG_H
#define GUI_LAUNCHER_DIALOG_H

#include "gui/dialog.h"
#include "engines/game.h"

namespace GUI {

class BrowserDialog;
class CommandSender;
class ListWidget;
class ButtonWidget;
class PicButtonWidget;
class GraphicsWidget;
class StaticTextWidget;
class EditTextWidget;
class SaveLoadChooser;

class LauncherDialog : public Dialog {
	typedef Common::String String;
	typedef Common::Array<Common::String> StringArray;

	typedef Common::U32String U32String;
	typedef Common::Array<Common::U32String> U32StringArray;
public:
	LauncherDialog();
	~LauncherDialog() override;

	void rebuild();

	void handleCommand(CommandSender *sender, uint32 cmd, uint32 data) override;

	void handleKeyDown(Common::KeyState state) override;
	void handleKeyUp(Common::KeyState state) override;
	void handleOtherEvent(const Common::Event &evt) override;
	bool doGameDetection(const Common::String &path);
	Common::String getGameConfig(int item, Common::String key);
protected:
	EditTextWidget  *_searchWidget;
	ListWidget		*_list;
	Widget			*_startButton;
	ButtonWidget	*_loadButton;
	Widget			*_editButton;
	Widget			*_removeButton;
#ifndef DISABLE_FANCY_THEMES
	GraphicsWidget		*_logo;
	GraphicsWidget		*_searchPic;
#endif
	StaticTextWidget	*_searchDesc;
	ButtonWidget	*_searchClearButton;
	StringArray		_domains;
	BrowserDialog	*_browser;
	SaveLoadChooser	*_loadDialog;

	String _search;

	void reflowLayout() override;

	/**
	 * Fill the list widget with all currently configured targets, and trigger
	 * a redraw.
	 */
	void updateListing();

	void updateButtons();

	void build();
	void clean();

	void open() override;
	void close() override;

	/**
	 * Handle "Add game..." button.
	 */
	virtual void addGame();
	void massAddGame();

	/**
	 * Handle "Remove game..." button.
	 */
	void removeGame(int item);

	/**
	 * Handle "Edit game..." button.
	 */
	void editGame(int item);

	/**
	 * Handle "Record..." button.
	 */
	void recordGame(int item);

	/**
	 * Handle "Load..." button.
	 */
	void loadGame(int item);

	/**
	 * Select the target with the given name in the launcher game list.
	 * Also scrolls the list so that the newly selected item is visible.
	 *
	 * @target	name of target to select
	 */
	void selectTarget(const String &target);
private:
	bool checkModifier(int modifier);
};

} // End of namespace GUI

#endif

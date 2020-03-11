#import "ConsoleWindowController.h"
#include "cocos2d.h"
#include "AppFrame.h"
#include <vector>
#include <string>

USING_NS_CC;

#define USE_CONSOLE_WINDOW

int main(int argc, char *argv[])
{
#ifdef USE_CONSOLE_WINDOW
    ConsoleWindowController *consoleController = [[ConsoleWindowController alloc] initWithWindowNibName:@"ConsoleWindow"];
    [consoleController.window orderFrontRegardless];
#endif
	std::vector<std::string> args;
	for (int i = 0; i < argc; ++i)
		args.emplace_back(argv[i]);
	lstg::AppFrame::setCmdLineArgs(args);
	int ret = lstg::AppFrame::getInstance()->run();
	lstg::AppFrame::destroyInstance();
	return ret;
}

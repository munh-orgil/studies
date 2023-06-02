switch windows

If you're using a modified version of Ubuntu specifically provided by ICPC and certain commands don't work as expected, it's difficult to provide a specific solution without knowing the modifications made to the system.

However, if you're unable to install additional packages or use external tools, you can try the following alternative method to switch between windows using built-in tools:

Open a terminal.

Use the following command to list all open windows:

```
wmctrl -l
This command will display a list of windows along with their IDs and titles.
```

Identify the window you want to switch to based on its title or ID.

To activate a specific window, use the following command:

```
wmctrl -i -a <window_id>
Replace <window_id> with the ID of the window you want to switch to.
```

For example, if you want to switch to a window with the title "Terminal," you can use the following command:

```
wmctrl -a "Terminal"
If you know the ID of the window, you can use it directly like this:
```
```
wmctrl -i -a 0x01234567
```
Please note that this alternative method relies on the wmctrl command, and it may or may not work as expected depending on the modifications made to the ICPC-provided Ubuntu image. If this method doesn't work, it's recommended to consult the ICPC documentation or reach out to the competition organizers for specific guidance on window management in their customized Ubuntu environment.
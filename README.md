# CP

## How to use

Generating the vscode snippets: Navigate to `/templates/` and then proceed to run `py -3 genTemplate.py`

Making files: 

Files are generated with the following command arguments:

`-f` - files separated by commas, will place them by default in the `/contest/` folder. For example `make -f 1,2,3` makes files `1.cpp, 2.cpp, 3.cpp`

`-l` - file template lengths separated by commas, will place them by default. The template lengths are `v, s, l` which stand for `VERYSHORT,SHORT,LONG` - corresponding to the files placed in `/templates/`.

By default, if using `-f` alone, `-f` will default to using the `v` length setting.

If the amount of lengths given is less than the files, `make` automatically pads the files using the `v` length setting. This can be changed by going into `make.py` and changing `'l'`

```
while len(LENGTHS) < len(FILES):
    LENGTHS.append('l')
```

Add `make.bat` to path, then you can run the file from anywhere using `make`. Ex. `make -f 1,2,3`. Make sure that the files are separated by commas and are in **one and only one** string.
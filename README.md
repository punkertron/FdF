# Coordinate Mapper and Image Renderer

This C project is designed to parse files containing coordinates and render them as images. Users can manipulate the rendered images by rotating, shifting, zooming, and more.

![MapDraw](https://github.com/punkertron/MapDraw/assets/82904352/3f9a9249-b9c2-4d07-8465-539c79c01358)

---
## Features

- Parse coordinate data from files.
- Render images based on the parsed coordinates.
- Perform various image transformations, such as rotation and zooming.
- Simple and user-friendly command-line interface.
- Ability to view the map from different angles (top, side).

---
## Usage
MiniLibX for Linux requires xorg, x11 and zlib, therefore you will need to install the following dependencies: xorg, libxext-dev and zlib1g-dev. Installing these dependencies on Ubuntu can be done as follows:

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
Afterwards, just type the `make` command.

After compilation is complete, use the programme as follows:
```bash
./fdf [path_to_file]
```
File (or map) must be a rectangle consisting of numbers with a .fdf file extension. Example ([42.fdf](test_maps/42.fdf)):
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

You can use the following commands:
| Action    | Buttons |
|-----------|---------|
| shift     | arrows  |
| zoom      | +/-     |
| rotate Y  | q/w     |
| rotate X  | a/s     |
| rotate Z  | z/x     |
| top view  | m       |
| size view | n       |
| default   | f       |
| exit      | Esc     |

---
## Additional Information
- Drawing is done using the [**MiniLibX**](https://github.com/42Paris/minilibx-linux) library.
- The code is written in accordance with [**norminette**](https://github.com/42School/norminette) style.
- The original name was FdF :-)

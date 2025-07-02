# Delaunay-Voronoi Visualizer

This program visualizes the duality between the **Delaunay Triangulation** and **Voronoi Diagram** interactively. Click inside the canvas to add new points and compute the triangulation in real time.

## Features

* Interactive canvas for point input via mouse clicks.
* Two toolbar buttons to toggle the rendering of Delaunay Triangles and Voronoi Cells.

## Demo



## Requirements

Tested with Qt 6 on Fedora. No external dependencies are needed.

## Build

To build with CMake:

```bash
mkdir build && cd build
cmake ..
make
./delaunay_voronoi_viz
```

## Usage

1- Click anywhere to add points.

2- Show/Hide triangulation or cells from the toolbar actions, or toggle both off to only view the point set.

3- Click File -> New Canvas to reset the points.

## Geometry

1- **Delaunay Triangulation**: Built using the Bowyer-Watson algorithm for incremental point updates.

2- **Voronoi Cells**: Derived from the Delaunay triangles.

## Code Structure

The program is modularized into two parts: **Core** and **UI**.

### Core

- Manages the point set and running the geometry algorithms, and can be used separately without a UI.
- Implements `QGraphicsScene` to add primitive shapes to the backend canvas.
- Includes the `SceneController` and data structures.

### UI

- Renders the canvas in an OpenGL widget through `QGraphicsView`.
- Includes the main window, toolbar and menubar.

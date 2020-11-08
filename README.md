# Godot Delaunay

```diff
- This is very WIP and only public because why not.
```

This is a port of [cppdelaunay](https://github.com/SirAnthony/cppdelaunay), which is a port of [as3delaunay](http://nodename.github.io/as3delaunay/), to a Godot module. It's mostly just the cppdelaunay code with a wrapper around to access the functionality through GDScript.

**Currently it only includes wrapper functionality for basic voronoi diagram generation** (setting the input nodes and getting the output edges), though the C++ code for delaunay triangulation is all there so it should be easy to add wrappers.

## Usage

You will need a fork/clone of the Godot source to use this.

It is best to add this as a submodule to your Godot source repo, to maintain independent version control.

From your Godot source root:

```
cd modules
git submodule add https://github.com/samuelbigos/godot_delaunay
```

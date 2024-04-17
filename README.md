# [ ⚠ IN PROGRESS... ]
# Warehouse Data Structures and API
>[!Note]
>This task was provided by [**Rockbite Games**](https://rockbitegames.com/) for the purpose of showcasing OOP skills and understanding of fundamentals.

<p align="center">
    <img src="https://github.com/hheghine/Warehouse-DataStructures-and-API/assets/119530584/40b50ec0-fa1f-426c-91d1-c74e1f2d07ca" alt="inventory" width="800" height="300">
</p>

---

## Some Intro

<b><i>In Sandship, the warehouse is a place where players can store their materials. It’s like an inventory. Players can have multiple warehouses, and each warehouse has a list of materials and their quantities.
Each material in the warehouse is of a certain material type, for example - iron, copper, bolt and so on. Each material type has some information about it like name, description, icon (all strings). Additionally, the material type knows its max capacity. (How much of that material can be ever held in a single warehouse as a max cap).
Materials can be added to the warehouse, or removed from it. Materials can also be moved from one warehouse to another as one transaction. Note that due to max material caps, moving a material can be either partial or fail altogether. So it needs a method that gets a warehouse reference to move items from (or to).</i></b>

## Task:

- Make classes and methods to handle this logic in terms of data. Come up with an ideal set of data structures for this task. What classes do you need, what methods do they need to have? Should you use arrays or maps? What’s the best OOP approach? Do you need interfaces or Generic types? Code with answers in mind.
- Make a list of proper API methods in order to work with this data. Your warehouse class should be intuitive and easy to use by another engineer. Maybe worth commenting on it too? 
- Have some ways of outputting current warehouse data so you can debug and test your results. Just a text output is fine.
- Make sure your lookup operations are fast and optimal. How costly is it to add or remove a material or query warehouse to know how much you have for each? Imagine this operation happening 100 times per second per material, is your code leaking memory or making GC crunch? Make sure things are optimal. 

## Optional:
- Implement proper notification/observer pattern and utilize that in your architecture.
- Add proper validation and exception handling mechanism. Make sure the warehouse always has proper/valid data no matter the input.

---
## File Hierarchy

```
Warehouse-DataStructures-and-API
│
├── inc
│   ├── AMaterial.hpp
│   ├── Materials
│   │   ├── Copper.hpp
│   │   ├── Iron.hpp
│   │   └── Lumisteel.hpp
│   └── Warehouse.hpp
│
└── src
    ├── AMaterial.cpp
    ├── Materials
    │   ├── Copper.cpp
    │   ├── Iron.cpp
    │   └── Lumisteel.cpp
    └── Warehouse.cpp
```

## Usage

```
git clone git@github.com:hheghine/Warehouse-DataStructures-and-API.git

cd Warehouse-DataStructures-and-API

make
```
Feel free to add your test cases or add your own materials ✨

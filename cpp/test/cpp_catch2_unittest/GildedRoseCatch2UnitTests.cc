#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.hpp"
#include "GildedRose.h"

TEST_CASE("GildedRoseUnitTest", "Foo")
{
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Foo" == app.items[0].name);
    REQUIRE(-1 == app.items[0].sellIn);
    REQUIRE(0 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest2", "Foo2")
{
    vector<Item> items;
    items.push_back(Item("Foo", 1, 0));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Foo" == app.items[0].name);
    REQUIRE(0 == app.items[0].sellIn);
    REQUIRE(0 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest3", "Foo3")
{
    vector<Item> items;
    items.push_back(Item("Foo", 1, 3));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Foo" == app.items[0].name);
    REQUIRE(0 == app.items[0].sellIn);
    REQUIRE(2 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest4", "Aged Brie")
{
    vector<Item> items;
    items.push_back(Item("Aged Brie", 1, 0));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Aged Brie" == app.items[0].name);
    REQUIRE(0 == app.items[0].sellIn);
    REQUIRE(1 == app.items[0].quality);

    app.items[0].quality = 50;

    app.updateQuality();
    REQUIRE(-1 == app.items[0].sellIn);
    REQUIRE(50 == app.items[0].quality);
    
    app.items[0].quality = 40;

    app.updateQuality();
    REQUIRE(-2 == app.items[0].sellIn);
    REQUIRE(42 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest5", "Sulfuras, Hand of Ragnaros")
{
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 5, 80));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(5 == app.items[0].sellIn);
    REQUIRE(80 == app.items[0].quality);

    app.items[0].quality = 10;
    app.updateQuality();
    REQUIRE(5 == app.items[0].sellIn);
    REQUIRE(10 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest6", "Backstage passes to a TAFKAL80ETC concert")
{
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(14 == app.items[0].sellIn);
    REQUIRE(21 == app.items[0].quality);

    app.items[0].sellIn = 10;

    app.updateQuality();
    REQUIRE(9 == app.items[0].sellIn);
    REQUIRE(23 == app.items[0].quality);
    
    app.items[0].sellIn = 5;

    app.updateQuality();
    REQUIRE(4 == app.items[0].sellIn);
    REQUIRE(26 == app.items[0].quality);
    
    app.items[0].sellIn = 0;

    app.updateQuality();
    REQUIRE(-1 == app.items[0].sellIn);
    REQUIRE(0 == app.items[0].quality);
    
    app.items[0].sellIn = 5;
    app.items[0].quality = 49;
    
    app.updateQuality();
    REQUIRE(4 == app.items[0].sellIn);
    REQUIRE(50 == app.items[0].quality);
}

TEST_CASE("GildedRoseUnitTest7", "Conjured Mana Cake")
{
    vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 15, 20));
    GildedRose app(items);
    app.updateQuality();
    REQUIRE(14 == app.items[0].sellIn);
    REQUIRE(18 == app.items[0].quality);

    app.items[0].sellIn = 0;

    app.updateQuality();
    REQUIRE(-1 == app.items[0].sellIn);
    REQUIRE(14 == app.items[0].quality);
}
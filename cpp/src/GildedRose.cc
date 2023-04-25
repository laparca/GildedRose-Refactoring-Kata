#include "GildedRose.h"
#include <map>
#include <functional>

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality() 
{
    auto defaultUpdateItem = [](Item& item)
    {
        item.sellIn --;
        
        if (item.quality > 0)
        {
            item.quality --;
        }

        if (item.sellIn < 0 && item.quality > 0)
        {
            item.quality --;
        }
    };

    auto doNothingUpdateItem = [](Item&) {};

    auto backStageUpdateItem = [](Item& item)
    {
        if (item.quality < 50)
            item.quality ++;
    
        if (item.sellIn < 11 && item.quality < 50)
           item.quality ++;

        if (item.sellIn < 6 && item.quality < 50)
            item.quality ++;

    
        item.sellIn --;

        if (item.sellIn < 0)
            item.quality = 0;
    };

    auto agedBrieUpdateItem = [](Item& item)
    {
        if (item.quality < 50)
           item.quality ++;
        if (item.sellIn < 0 && item.quality < 50)
            item.quality ++;
        item.sellIn --;
    };

    auto conjuredManaCacke = [defaultUpdateItem](Item& item) {
        defaultUpdateItem(item);
        defaultUpdateItem(item);
        item.sellIn ++;
    };

    std::map<std::string, std::function<void(Item&)>> changeFactor {
        {"default", defaultUpdateItem},
        {"Sulfuras, Hand of Ragnaros", doNothingUpdateItem},
        {"Aged Brie", agedBrieUpdateItem},
        {"Conjured Mana Cake", conjuredManaCacke},
        {"Backstage passes to a TAFKAL80ETC concert", backStageUpdateItem}
    };

    for (auto& item: items)
    {
        auto changer = [&changeFactor, item, &defaultUpdateItem]() -> std::function<void(Item&)>
        {
            try {
                return changeFactor.at(item.name);
            }
            catch(...)
            {
                return defaultUpdateItem;
            }
        }();

        changer(item);
    }
}

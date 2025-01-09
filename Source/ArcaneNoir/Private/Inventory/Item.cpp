// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Item.h"

UItem::UItem()
{
	ItemData.Name = "Unamed Item";
	ItemData.GridWidth = 1;
	ItemData.GridHeight = 1;
	ItemData.Icon = nullptr;
	ItemData.ItemActorClass = nullptr;
}

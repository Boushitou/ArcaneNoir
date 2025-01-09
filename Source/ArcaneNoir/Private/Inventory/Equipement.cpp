// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Equipement.h"

UEquipement::UEquipement()
{
	EquipementData.RequiredLevel = 1;
	EquipementData.AttributeRequired = TMap<FGuid, int32>();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "InventoryWidget.h"
#include "ExampleInventoryCharacter.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Character = Cast<AExampleInventoryCharacter>(GetOwningPlayerPawn());
	parent_name = GetParent()->GetDisplayLabel();
}

void UInventorySlotWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ButtonItem->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnClick);
}


void UInventorySlotWidget::OnClick()
{
	if (parent_name == "GP_NearbyInventory") {
		Character->PickupItem(SlotIndex);
		AActor* AssociatedActor = Character->OverlappingItems[SlotIndex];
		AssociatedActor->Destroy();
	}

	if (parent_name == "GP_Inventory") {
		Character->DropItem(SlotIndex);
	}
}

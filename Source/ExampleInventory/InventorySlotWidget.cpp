// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "ExampleInventoryCharacter.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonItem->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnClick);

	Character = Cast<AExampleInventoryCharacter>(GetOwningPlayerPawn());

	parent_name = GetParent()->GetDisplayLabel();
}


void UInventorySlotWidget::OnClick()
{
	if (parent_name == "GP_NearbyInventory") {
	
		AActor* AssociatedActor = Character->OverlappingItems[SlotIndex];
		//Character->Inventory.Add();
		AssociatedActor->Destroy();
	}
	
	//Character->DropItem(SlotIndex);

}

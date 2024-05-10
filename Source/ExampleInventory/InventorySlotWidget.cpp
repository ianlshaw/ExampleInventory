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

	UE_LOG(LogTemp, Warning, TEXT("UInventorySlotWidget::OnInitialized"));
	ButtonItem->OnClicked.AddDynamic(this, &UInventorySlotWidget::OnClick);
}


void UInventorySlotWidget::OnClick()
{
	if (parent_name == "GP_NearbyInventory") {
	
		AActor* AssociatedActor = Character->OverlappingItems[SlotIndex];
		//Character->Inventory.Add(AssociatedItem->GetClass());
		AssociatedActor->Destroy();
		
		FName temp_item_name = AssociatedItem->GetFName();
			UE_LOG(LogTemp, Warning, TEXT("My Name: %s"), *temp_item_name.ToString());

	}

	if (parent_name == "GP_Inventory") {
		Character->DropItem(SlotIndex);

	}
	

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "ExampleInventoryCharacter.h"
#include "Item.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget constructor")));

	// You can give the TSubclassOf variable a default class to use like this.
	InventorySlotWidgetClass = UInventorySlotWidget::StaticClass();
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::construct")));
	DrawInventory();
}

void UInventoryWidget::DrawInventory()
{
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::DrawInventory")));

	APawn* owning_player_pawn = GetOwningPlayerPawn();
	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(owning_player_pawn);


	// Loop around the conventional inventory and add each element to the grid panel
	for (int32 Index = 0; Index != EIC->Inventory.Num(); ++Index)
	{
		AItem* item_as_item = EIC->NearbyInventory[Index].GetDefaultObject();
		AddItemToGridPanel(GP_Inventory, item_as_item, Index);
	}

	// Loop around the characters NearbyInventory and add each element to the nearby inventory grid panel
	for (int32 Index = 0; Index != EIC->NearbyInventory.Num(); ++Index)
	{		
		AItem* item_as_item = EIC->NearbyInventory[Index].GetDefaultObject();
		AddItemToGridPanel(GP_NearbyInventory, item_as_item, Index);
	}
}

void UInventoryWidget::AddItemToGridPanel(UUniformGridPanel* GridPanel, AItem* Item, int Row)
{
	// Create widget from inventory slot class defined in the editor.
	UUserWidget* item_slot_as_user_widget = CreateWidget(GetOwningPlayer(), InventorySlotWidgetClass);

	// Convert it to custom class, so we get access to member variables.
	UInventorySlotWidget* item_slot_as_inventory_slot_widget = Cast<UInventorySlotWidget>(item_slot_as_user_widget);

	// Set the name of the item according to the class.
	item_slot_as_inventory_slot_widget->TextBlockName->SetText(Item->ItemName);

	// Set the icon of the item according to the class.
	item_slot_as_inventory_slot_widget->ImageIcon->SetBrushFromTexture(Item->ItemIcon, true);

	// Add the slot widget to the inventory grid panel
	GridPanel->AddChildToUniformGrid(item_slot_as_inventory_slot_widget, Row, 0);
}
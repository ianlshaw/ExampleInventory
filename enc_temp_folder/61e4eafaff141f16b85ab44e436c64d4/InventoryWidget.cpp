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


	for (int32 Index = 0; Index != EIC->Inventory.Num(); ++Index)
	//for (auto& item : EIC->Inventory)
	{
	
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("inside inventory loop")));
	
		//each_slot_widget.Name = item.Name;
		UUserWidget* slot_widget = CreateWidget(GetOwningPlayer(), InventorySlotWidgetClass, "GEOFF");
		UInventorySlotWidget* slot_widget_as_uinventoryslotwidget= Cast<UInventorySlotWidget>(slot_widget);
		//InventorySlotWidgets.Add(slot_widget_as_uinventoryslotwidget);
		AddEntry(slot_widget_as_uinventoryslotwidget, Index, 0);
		UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), Index);

	

	}

	//index = 0;
	//for (auto& widget : InventorySlotWidgets)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("InventorySlotWidgets")));
	//	index++;
	//}


	for (auto& item : EIC->NearbyInventory)
	{

	}
}

void UInventoryWidget::AddEntry(UInventorySlotWidget* ChildWidget, int row, int col)
{
	GP_Inventory->AddChildToUniformGrid(ChildWidget, row, col);

}


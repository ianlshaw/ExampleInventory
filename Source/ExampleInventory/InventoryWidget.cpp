// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "ExampleInventoryCharacter.h"

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hi from UInventoryWidget::DrawInventory")));

	APawn* owning_player_pawn = GetOwningPlayerPawn();
	AExampleInventoryCharacter* EIC = Cast<AExampleInventoryCharacter>(owning_player_pawn);

	int index = 0;
	for (auto& item : EIC->Inventory)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("inside inventory loop")));

		//each_slot_widget.Name = item.Name;
		UUserWidget* slot_widget = CreateWidget(GetOwningPlayer(), InventorySlotWidgetClass, "GEOFF");
		GP_Inventory->AddChildToUniformGrid(slot_widget, index, 0);

		index++;
	}

	for (auto& item : EIC->NearbyInventory)
	{

	}
}


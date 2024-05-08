// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "InventorySlotWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEINVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	/** Widget constructor. */
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUniformGridPanel* GP_Inventory;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUniformGridPanel* GP_NearbyInventory;
		
		UFUNCTION()
		virtual void NativeConstruct();

		UFUNCTION(BlueprintImplementableEvent)
			void redraw();

		UFUNCTION(BlueprintCallable)
			void DrawInventory();

		TArray<UInventorySlotWidget*> InventorySlotWidgets;

		UFUNCTION()
			void AddEntry(UInventorySlotWidget* ChildWidget, int row, int col);


protected:

	/** Class to use for inventory cells. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Parameters")
		TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;
		
	
};

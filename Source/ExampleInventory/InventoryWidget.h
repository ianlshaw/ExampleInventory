// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"

#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEINVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()


public:

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUniformGridPanel* GP_Inventory;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUniformGridPanel* GP_NearbyInventory;
		
		UFUNCTION()
		virtual void NativeConstruct();

		UFUNCTION(BlueprintImplementableEvent)
			void redraw();

		
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridSlot.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEINVENTORY_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** Widget constructor. */
	UInventorySlotWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UTexture2D* ItemIcon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ButtonItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTextBlock* TextBlockName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UImage* ImageIcon;

	UPROPERTY()
		int SlotIndex;

	UPROPERTY()
		class AExampleInventoryCharacter* Character;

	UPROPERTY()
		FString parent_name;

	//UPROPERTY()
//		AItem* AssociatedItem;

	UFUNCTION()
		virtual void NativeConstruct();

	UFUNCTION()
		void OnClick();

};

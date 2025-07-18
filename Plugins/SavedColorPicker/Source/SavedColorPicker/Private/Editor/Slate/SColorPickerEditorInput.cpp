﻿#include "Editor/Slate/SColorPickerEditorInput.h"

#include "SlateOptMacros.h"
#include "SavedColorPicker/SavedColorPickerConstants.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SColorPickerEditorInput::Construct(const FArguments& InArgs)
{
	OnTextChanged = InArgs._OnTextChanged;
	OnCommitted = InArgs._OnCommitted;

	SAssignNew(CategoryTitleTextBlock, STextBlock).Text(
		TAttribute<FText>::CreateLambda([this]()
		{
			return FText::FromString(CurrentCategoryTitle);
		}));

	SAssignNew(CategoryEditTitleBlock, SEditableTextBox)
	.HintText(FText::FromString(
		TEXT("Input Category Title, If you press |, Category is divide")))
	.OnTextChanged(this, &SColorPickerEditorInput::HandleTextChanged)
	.OnTextCommitted(this, &SColorPickerEditorInput::HandleTextCommitted);

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().Padding(10)
		[
			CategoryTitleTextBlock.ToSharedRef()
		]
		+ SVerticalBox::Slot().Padding(10).AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().Padding(5)
			[
				CategoryEditTitleBlock.ToSharedRef()
			]
			+ SHorizontalBox::Slot().Padding(5).AutoWidth()
			[
				SNew(SButton).Text(FText::FromString(TEXT("Enter")))
				// .OnClicked_Lambda(
				// 	this, &SColorPickerEditorInput::HandleTextCommitted)
			]
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SColorPickerEditorInput::HandleTextChanged(const FText& NewText)
{
	if (NewText.ToString().Len() <= 1 || !NewText.ToString().EndsWith("|"))
	{
		return;
	}

	// |를 제거한 원본 타이틀만 가져옴
	FString NewString = NewText.ToString();
	NewString.RemoveAt(NewString.Len() - 1);
	AddCategoryTitle_Internal(NewString);
}

void SColorPickerEditorInput::HandleTextCommitted(const FText& Text
												, ETextCommit::Type CommitType)
{
	if (CommitType == ETextCommit::Type::OnEnter)
	{
		if (Text.ToString().Len() == 0)
		{
			return;
		}

		if (Text.ToString().EndsWith("|"))
		{
			return;
		}

		if (AddCategoryTitle_Internal(Text.ToString()))
		{
			// FSlateApplication::Get().SetKeyboardFocus(CategoryEditTitleBlock);
		}
	}
}

bool SColorPickerEditorInput::AddCategoryTitle_Internal(
	const FString& TextValue)
{
	// 이후 Category Edit TextBlock을 초기화
	CategoryEditTitleBlock->SetText(FText::FromString(TEXT("")));

	// 배열에 타이틀 추가
	// 추가 전에 카테고리 한도치에 이미 도달한 경우 불가능하게 처리함
	if (CurrentCategoryList.Num() >= SavedColorPickerConstants::MaxDepthCount)
	{
		// TODO: 에러 알림 Notify 호출하기
		return false;
	}

	CurrentCategoryList.Add(TextValue);

	FString CategoryTitle;
	for (const FString& Category : CurrentCategoryList)
	{
		CategoryTitle += " " + Category + " |";
	}

	CategoryTitle.RemoveAt(CategoryTitle.Len() - 1);
	CurrentCategoryTitle = CategoryTitle;

	return true;
}

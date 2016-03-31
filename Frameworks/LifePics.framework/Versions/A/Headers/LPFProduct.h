//
//  LPFProduct.h
//  LifePics
//
//  Created by Christian Beach on 5/21/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LifePics/LifePics.h>
#import "LPFImage.h"

typedef NS_ENUM(NSInteger, LPFProductCategory) {
    LPFProductCategoryUnknown = 0,
    LPFProductCategoryPrints,
    LPFProductCategoryCardsCalendars,
    LPFProductCategoryPhotoBooks,
    LPFProductCategoryGift,
    LPFProductCategoryAdditionalProducts,
    LPFProductCategoryAdditionalProductsLifePics,
    LPFProductCategoryCanvas = 47
};

@class LPFProductAttribute;
@class LPFProductGroup;

@interface LPFProduct : NSObject <NSCoding>

// Original properties (fixed).
@property (nonatomic, copy) NSString *productID;
@property (nonatomic, weak) LPFProductGroup *productGroup;  // Exists only if created from a product group. See -[LPFProductGroup initWithDictionary];
@property (nonatomic, copy) NSString *sku;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSDecimalNumber *basePrice;
@property (nonatomic, copy) NSString *widthString;
@property (nonatomic, copy) NSString *heightString;
@property (nonatomic, copy) NSDecimalNumber *widthResolution;
@property (nonatomic, copy) NSDecimalNumber *lengthResolution;
@property (nonatomic) LPFProductCategory productCategory;
@property (nonatomic) LPFProductCategory productSubCategory;
@property (nonatomic, copy) NSURL *previewImageURL;
@property (nonatomic, copy) NSString *previewText;
@property (nonatomic, strong) NSMutableArray *attributes;  // LPFProductAttributes
@property (assign, nonatomic) BOOL selected;
//hxliu from NL added new property
@property (nonatomic, strong) NSMutableArray *pricingTier;

// New properties.
@property (nonatomic) double width;
@property (nonatomic) double height;
@property (nonatomic, readonly) LPFImageOrientation imageOrientation;

// Class Methods
+ (LPFProduct *)printProductWithWidth:(double)width height:(double)length;
+ (LPFProduct *)productWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isSimilarToProduct:(LPFProduct *)anotherProduct;  // Returns YES if the category and size match.
- (LPFProductAttribute *)productAttributeSimilarToAttribute:(LPFProductAttribute *)attribute;
- (BOOL)isSimilarToProductForGenericApp:(LPFProduct *)anotherProduct andHasAttribute:(LPFProductAttribute *)attribute;//match width / height / attribute for generic app
- (NSUInteger)indexOfDefaultAttribute;

@end
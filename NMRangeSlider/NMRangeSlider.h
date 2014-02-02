//
//  RangeSlider.h
//  RangeSlider
//
//
// The layout of this on the screen, if you are looking to align the image and thumbs precisely,
// follows the following logic.
// The trackImage should be as wide as the maxValue-minValue * desired pts/interval
// plus 1/2 of each of the thumb widths (since the design assumes that the thumb center is the point of alignment)
// plus the insets from each side (to allow the ends of the graph to be wider than half of the thumb images).
//
//
//  Created by Murray Hughes on 04/08/2012
//  Copyright 2011 Null Monkey Pty Ltd. All rights reserved.
//
// Inspried by: https://github.com/buildmobile/iosrangeslider

#import <UIKit/UIKit.h>

@interface NMRangeSlider : UIControl


@property(assign, nonatomic) float minimumValue; // default 0.0
@property(assign, nonatomic) float maximumValue; // default 1.0
@property(assign, nonatomic) float minimumRange; // default 0.0. This is the minimum distance between between the upper and lower values
@property(assign, nonatomic) float stepValue; // default 0.0 (disabled)

// If NO the slider will move freely with the tounch. When the touch ends, the value will snap to the nearest step value
// If YES the slider will stay in its current position until it reaches a new step value.
// default NO
@property(assign, nonatomic) BOOL stepValueContinuously;

@property(assign, nonatomic) BOOL continuous; // defafult YES, indicating whether changes in the sliders value generate continuous update events.


@property(assign, nonatomic) float lowerValue; // default 0.0. this value will be pinned to min/max
@property(assign, nonatomic) float upperValue;// default 1.0. this value will be pinned to min/max
@property(readonly, nonatomic) CGPoint lowerCenter; // center location for the lower handle control
@property(readonly, nonatomic) CGPoint upperCenter; // center location for the upper handle control
@property(assign, nonatomic) float lowerMaximumValue; // maximum value for left thumb
@property(assign, nonatomic) float upperMinimumValue; // minimum value for right thumb

@property (assign, nonatomic) float leftHandleInset;
@property (assign, nonatomic) float rightHandleInset;
@property (assign, nonatomic) BOOL lowerHandleHidden;
@property (assign, nonatomic) BOOL upperHandleHidden;

// Images, these should be set before the control is displayed.
// If they are not set, then the default images are used.
// eg viewDidLoad


//Probably should add support for all control states... Anyone?

@property(retain, nonatomic) UIImage* lowerHandleImageNormal;
@property(retain, nonatomic) UIImage* lowerHandleImageHighlighted;

@property(retain, nonatomic) UIImage* upperHandleImageNormal;
@property(retain, nonatomic) UIImage* upperHandleImageHighlighted;

@property(retain, nonatomic) UIImage* trackImage;

// track image when lower value is higher than the upper value (eg. when minimum range is negative
@property(retain, nonatomic) UIImage* trackCrossedOverImage;

@property(retain, nonatomic) UIImage* trackBackgroundImage;

// default 5.0. Used to change the touch area for the handles
@property (assign, nonatomic) BOOL lowerHandleHorizontalTouchPadding;
@property (assign, nonatomic) BOOL lowerHandleVerticalTouchPadding;
@property (assign, nonatomic) BOOL upperHandleHorizontalTouchPadding;
@property (assign, nonatomic) BOOL upperHandleVerticalTouchPadding;


//Setting the lower/upper values with an animation :-)
- (void)setLowerValue:(float)lowerValue animated:(BOOL) animated;
- (void)setUpperValue:(float)upperValue animated:(BOOL) animated;
- (void) setLowerValue:(float) lowerValue upperValue:(float) upperValue animated:(BOOL)animated;

@end

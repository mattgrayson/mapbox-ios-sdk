//
//  RMCircle.h
//
// Copyright (c) 2008-2010, Route-Me Contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#import <Foundation/Foundation.h>
#import "RMFoundation.h"
#import "RMMapLayer.h"

@class RMMapContents;

@interface RMCircle : RMMapLayer <RMMovingMapLayer> {
@private
	RMMapContents *mapContents;
	CAShapeLayer *shapeLayer;
	
	CLLocationCoordinate2D latLong;
	RMProjectedPoint projectedLocation;
	BOOL enableDragging;
	BOOL enableRotation;
	
	UIColor *lineColor;
	UIColor *fillColor;
	CGFloat radiusInMeters;
	CGFloat lineWidthInPixels;
	BOOL scaleLineWidth;

	CGMutablePathRef circlePath;
}

@property (nonatomic, retain) CAShapeLayer *shapeLayer;
@property (nonatomic, assign) RMProjectedPoint projectedLocation;
@property (assign) BOOL enableDragging;
@property (assign) BOOL enableRotation;
@property (nonatomic, retain) UIColor *lineColor;
@property (nonatomic, retain) UIColor *fillColor;
@property (nonatomic, assign) CGFloat radiusInMeters;
@property (nonatomic, assign) CGFloat lineWidthInPixels;

- (id)initWithContents:(RMMapContents *)aContents radiusInMeters:(CGFloat)newRadiusInMeters latLong:(CLLocationCoordinate2D)newLatLong;
- (void)moveToLatLong:(CLLocationCoordinate2D)newLatLong;

@end

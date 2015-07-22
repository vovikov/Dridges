/*******************************************************************************
 *
 * Copyright 2012 Zack Grossbart
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#import <Foundation/Foundation.h>
#import "Cocos2d.h"

/** 
 * The river node represents a span of rivers on the board with an array of sprites
 */
@interface RiverNode : NSObject

/**
 * Create a new RiverNode with the specified frame and set of sprites.
 *
 * @param frame the rectangle defining the total bounds of this river
 * @param rivers the array of CCSprites that make up this river
 * @param vert true if this river is vertical and false otherwise
 * @param the side of this river as defined in BridgeColors.h
 */
-(id)initWithFrame: (CGRect) frame rivers:(NSMutableArray*) rivers vert:(BOOL) vert side:(int) side;

/**
 * Returns true if this specific sprite is contained in this node and false
 * otherwise.
 */
-(bool)contains: (CCSprite*) river;

/**
 * The frame surrounding this river
 */
@property (readonly) CGRect frame;

/**
 * The river sprites contained in this river node
 */
@property (readonly, retain) NSMutableArray *rivers;


@end

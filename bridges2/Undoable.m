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

#import "Undoable.h"

@interface Undoable()
@property (readwrite) CGPoint pos;
@property (readwrite) BridgeColor color;
@property (readwrite, assign) id<GameNode> node;
@property (nonatomic, assign, readwrite) int coins;
@property (nonatomic, assign, readwrite) bool canVisit;
@end

@implementation Undoable

-(id) initWithPosAndNode:(CGPoint) pos node:(id<GameNode>) node color:(BridgeColor) color coins:(int) coins canVisit:(bool) canVisit {
    if( (self=[super init] )) {
        self.pos = pos;
        self.node = node;
        self.color = color;
        self.coins = coins;
        self.canVisit = canVisit;
    }
    
    return self;
}

@end

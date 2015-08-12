//
//  ProjectFile.h
//  Coding_iOS
//
//  Created by Ease on 14/11/13.
//  Copyright (c) 2014年 Coding. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "User.h"


typedef NS_ENUM(NSInteger, DownloadState){
    DownloadStateDefault = 0,
    DownloadStateDownloading,
    DownloadStatePausing,
    DownloadStateDownloaded
};

@class Coding_DownloadTask;

@interface ProjectFile : NSObject
@property (readwrite, nonatomic, strong) NSDate *created_at, *updated_at;
@property (readwrite, nonatomic, strong) NSNumber *file_id, *owner_id, *parent_id, *type, *current_user_role_id, *size, *project_id;
@property (readwrite, nonatomic, strong) NSString *name, *fileType, *owner_preview, *preview, *storage_key, *storage_type, *title;
@property (readwrite, nonatomic, strong) User *owner;
@property (readwrite, nonatomic, strong) NSString *diskFileName;

+(ProjectFile *)fileWithFileId:(NSNumber *)fileId andProjectId:(NSNumber *)project_id;
- (instancetype)initWithFileId:(NSNumber *)fileId inProject:(NSString *)project_name ofUser:(NSString *)project_owner_name;

- (BOOL)isEmpty;

- (NSString *)fileIconName;
- (DownloadState)downloadState;

- (Coding_DownloadTask *)cDownloadTask;
- (NSURL *)hasBeenDownload;
- (NSString *)downloadPath;

- (NSString *)toDeletePath;
- (NSDictionary *)toDeleteParams;

- (NSDictionary *)toMoveToParams;

- (NSString *)toDetailPath;
@end

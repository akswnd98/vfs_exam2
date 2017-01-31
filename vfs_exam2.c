#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/list.h>
#include <linux/dcache.h>
#include "/usr/src/linux-3.18.36/fs/mount.h"

static int __init vfs_exam2_init(void) {
    const char *fst_name = "xfs";
    struct file_system_type *ffst = get_fs_type(fst_name);
    struct file_system_type *fst = ffst;
    struct super_block *fsb = hlist_entry(fst->fs_supers.first->next, struct super_block, s_instances);
    struct super_block *sb = fsb;
    struct dentry *rootDen = fsb->s_root;
    
    while(1) {
        if(fst->name != NULL) {
            printk(KERN_EMERG "file system type: %s\n", fst->name);
        }
        if(fst->fs_supers.first == NULL) {
            fst = fst->next;
            continue;
        }
        fsb = hlist_entry(fst->fs_supers.first, struct super_block, s_instances);
        sb = fsb;
         
        while(1) {
            if(sb->s_root != NULL) {
                if(sb->s_root->d_name.name != NULL) {
                    printk(KERN_EMERG "    root dentry: %s\n", sb->s_root->d_name.name);
                }
            }
            if(sb->s_instances.next == NULL) {
                break;
            }
            sb = hlist_entry(sb->s_instances.next, struct super_block, s_instances);
        }
        printk(KERN_EMERG "----------------------------------------------------------------\n");

        if(fst->next == NULL) {
            break;
        }
        fst = fst->next;
    }

    /* while(1) {
        if(fst->name != NULL) {
            printk(KERN_EMERG "file system type: %s", fst->name);
        }
        if(fst->next == NULL) {
            break;
        }
        fst = fst->next;
    } */
    return 0;
}

static void __exit vfs_exam2_exit(void) {

}

module_init(vfs_exam2_init);
module_exit(vfs_exam2_exit);
MODULE_LICENSE("GPL");

import shutil
import argparse


def copy_include_dir(src_dir, dst_dir):
    shutil.copytree(src_dir, dst_dir, dirs_exist_ok=True)


def parse_args():
    parser = argparse.ArgumentParser(description="Copy include directory")
    parser.add_argument("src_dir", type=str, help="Source directory")
    parser.add_argument("dst_dir", type=str, help="Destination directory")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    copy_include_dir(args.src_dir, args.dst_dir)
